function solution(picks, minerals) {
  function mineralToNum(mineral) {
    switch (mineral) {
      case "diamond":
        return 25;
      case "iron":
        return 5;
      case "stone":
        return 1;
      default:
        return 0;
    }
  }
  const totalPicks = picks.reduce((acc, val) => acc + val, 0);
  if (totalPicks * 5 < minerals.length) {
    minerals = minerals.slice(0, totalPicks * 5); // 커버 가능한 개수만큼만 자르기
  }

  let fatigueArr = [];
  // 5개씩 묶었을 때 피로도 높은 순으로 정렬
  for (let i = 0; i < minerals.length; i += 5) {
    let tempFatigue = 0;
    for (let j = i; j < i + 5; j++) tempFatigue += mineralToNum(minerals[j]); // undefined

    let tempMinerals = [...minerals].slice(i, i + 5);

    fatigueArr.push([tempFatigue, tempMinerals]);
  }
  fatigueArr.sort((a, b) => b[0] - a[0]);

  function getMinerals(mineral, curPickIndex) {
    // 0, 1, 2
    switch (mineral) {
      case "diamond":
        return 5 ** curPickIndex;
      case "iron":
        return curPickIndex === 2 ? 5 : 1;
      case "stone":
        return 1;
    }
  }
  function calFatigue(curMinerals, picks) {
    let [diamond, iron, stone] = picks;
    let curPickIndex = diamond > 0 ? 0 : iron > 0 ? 1 : 2;

    picks[curPickIndex]--; // 사용했으니까 하나 줄이기
    return (curMinerals = curMinerals
      .map((mineral) => getMinerals(mineral, curPickIndex))
      .reduce((acc, val) => acc + val));
  }

  let totalFatigue = 0;
  for (let i = 0; i < fatigueArr.length; i++)
    totalFatigue += calFatigue(fatigueArr[i][1], picks);

  return totalFatigue;
}

const picks = [0, 1, 1];

const minerals = [
  "diamond",
  "diamond",
  "diamond",
  "diamond",
  "diamond",
  "iron",
  "iron",
  "iron",
  "iron",
  "iron",
  "diamond",
];
console.log(solution(picks, minerals));

// TODO: 그리디 정의

// TODO: array.slice, array.splice 체화시키기
