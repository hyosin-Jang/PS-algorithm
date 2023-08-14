function solution(wallpaper) {
  var answer = [];

  let rStart, rEnd, cStart, cEnd;

  // 1. row 순회
  let minR = Infinity;
  let maxR = -Infinity;
  for (let i = 0; i < wallpaper.length; i++) {
    if (wallpaper[i].includes("#")) {
      // 해당 행에 #이 존재한다면
      if (minR > i) minR = i;
      if (maxR < i) maxR = i;
    }
  }
  // 90도 회전
  let newArr = Array.from({ length: wallpaper[0].length }, () =>
    new Array(wallpaper.length).fill(0)
  );

  (rStart = minR), (rEnd = maxR);

  minR = Infinity;
  maxR = -Infinity;

  for (let i = 0; i < newArr.length; i++) {
    for (let j = 0; j < newArr[0].length; j++) {
      newArr[i][j] = wallpaper[j][i];
    }
  }

  for (let i = 0; i < newArr.length; i++) {
    let wallPaperRow = newArr[i].join("");
    if (wallPaperRow.includes("#")) {
      // 해당 행에 #이 존재한다면
      if (minR > i) minR = i;
      if (maxR < i) maxR = i;
    }
  }
  (cStart = minR), (cEnd = maxR);

  answer = [rStart, cStart, rEnd + 1, cEnd + 1];

  return answer;
}

wallpaper = [
  ".##...##.",
  "#..#.#..#",
  "#...#...#",
  ".#.....#.",
  "..#...#..",
  "...#.#...",
  "....#....",
];

solution(wallpaper);
