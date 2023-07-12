function solution(genres, plays) {
  const genreArr = [];

  const map = new Map();
  // 1. 순회하면서 map에 총합 저장 > 내림차순 정렬한 key(장르)순서대로 answer에 담음
  for (let i = 0; i < genres.length; i++) {
    map.set(genres[i], (map.get(genres[i]) || 0) + plays[i]);
  }

  // 2. map -> 배열 -> 정렬
  const sortedMap = Array.from(map).sort((a, b) => b[1] - a[1]);

  // 3. 각 장르별 play 횟수, id를 가지고 있는 객체 배열 만들기
  for (let i = 0; i < sortedMap.length; i++) {
    const curGenre = sortedMap[i][0];
    const idxArr = genres
      .map((genre, idx) => {
        return genre === curGenre ? idx : -1;
      })
      .filter((index) => index !== -1);

    let playArr = [];
    for (let j = 0; j < idxArr.length; j++) {
      playArr.push({ idx: idxArr[j], play: plays[idxArr[j]] });
    }
    playArr.sort((a, b) => {
      if (b.play === a.play) {
        return a.idx - b.idx;
      }
      return b.play - a.play;
    });

    if (playArr.length === 1) {
      genreArr.push(playArr[0].idx);
      continue;
    }
    genreArr.push(playArr[0].idx, playArr[1].idx);
  }

  return genreArr;
}

const genres = ["classic", "pop", "classic", "classic", "pop"];
const plays = [500, 600, 150, 800, 2500];
solution(genres, plays);
