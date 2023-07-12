function solution(grid) {
	// grid ["SL","LR"]
	const answer = []
	const [N, M] = [grid.length, grid[0].length]

	const routes = {}
	for (let r = 0; r < N; r++) {
		routes[r] = {}
		for (let c = 0; c < M; c++) {
			routes[r][c] = {
				u: 0,
				d: 0,
				l: 0,
				r: 0,
			}
		}
	}

	const bfs = (startR, startC, startDir) => {
		const queue = [[startR, startC, startDir, 0]]

		while (true) {
			let [r, c, dir, len] = queue.pop()
			r = r == N ? 0 : r === -1 ? N - 1 : r
			c = c === M ? 0 : c === -1 ? M - 1 : c

         if(r === startR && c === startC && dir === startDir && len){
            return len
         }

         routes[r][c][dir] = 1

         switch(grid[r][c]){
            case 'S':
               queue.push(
                  dir === 'u':
               )
         }
		}
	}
}

solution(["SL", "LR"])
