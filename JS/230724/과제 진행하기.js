function solution(plans) {
  var answer = []; // push: 뒤에서부터 넣기

  // 1. 시간 -> 분으로 바꾸고, 시간 내림차순 정렬
  plans = plans.map((plan) => {
    const [name, startTime, playTime] = plan;
    const [hour, min] = startTime.split(":").map(Number);
    const timeToMin = hour * 60 + min;
    return [name, timeToMin, parseInt(playTime)];
  });

  plans.sort((a, b) => b[1] - a[1]);

  const waitQueue = []; // 대기 배열
  let curAssign = ""; // 현재 붙잡고 있는 과제

  // 2. 새로운 과제가 소진될때까지 반복
  while (plans.length) {
    curAssign = plans.pop(); // 내림차순으로 정렬되어 있으므로 제일 뒤에 있는게 가장 빨리 시작하는 과제
    let [curName, curStart, curPlay] = curAssign;

    let lastIdx = plans.length - 1;

    // 마지막 과제라면 그냥 넣고 종료
    if (lastIdx === -1) {
      answer.push(curName);
      break;
    }

    let nextStart = plans[lastIdx][1];

    // 3. 현재과제는 끝내고 바로 다음과제 시작, 대기큐에 넣을 필요 없음
    if (curStart + curPlay === nextStart) {
      answer.push(curName);

      // 중간에 다음과제 시작해야하므로 대기큐에 남은시간 넣어줘야하는 상황
    } else if (curStart + curPlay > nextStart) {
      waitQueue.push([curName, curPlay - nextStart + curStart]);

      // 그리고 다음 아이템으로 넘어감
    } else if (curStart + curPlay < nextStart) {
      // 현재 아이템은 끝났고 다음 아이템 시작시간까지 waitQueue에 있는 것 처리
      answer.push(curName);

      // 대기큐에 있는 과제 계산할 때 필요
      let curAssignFinishTime = curStart + curPlay;
      while (waitQueue.length) {
        // 가장 최근에 멈춘 과제 끝내기

        // 과제 끝낸 시간에 새로시작해야 하는 과제와 멈춘과제 시간이 같다면 종료
        if (curAssignFinishTime === plans.at(-1)[1]) break;
        let lastStopAssign = waitQueue.pop();
        let [lastStopName, remainTime] = lastStopAssign;

        // 현재 과제 끝난시간 ~ 다음과제 시작시간 사이의 남는 시간 안에 대기큐 과제를 할 수 있다면
        if (nextStart - curAssignFinishTime >= remainTime) {
          answer.push(lastStopName); // 끝냈으니까 배열에 넣어주기
          curAssignFinishTime += remainTime; // 남은 과제 처리했으니까 종료
        } else {
          waitQueue.push([
            lastStopName,
            remainTime - (nextStart - curAssignFinishTime),
          ]);
          break;
        }
      }
    }
  }

  // 현재 과제를 다 끝냈는데도 남아있는 과제가 있다면 대기큐 과제 옮겨주기
  if (waitQueue.length) {
    while (waitQueue.length) {
      answer.push(waitQueue.pop()[0]);
    }
  }

  return answer;
}

const plans = [
  ["korean", "11:40", "30"],
  ["english", "12:10", "20"],
  ["math", "12:30", "40"],
];
solution(plans);
