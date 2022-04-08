function solution(board) {
  for (let i = 0; i < board.length; i++) {
    for (let j = board[i].length - 1; j > 0; j--) {
      if (board[i][j] === "#") {
        for (let k = j + 1; k < board[i].length; k++) {
          if (board[i][k] === ".") {
            board[i][k] = "#";
            board[i][k - 1] = ".";
          } else if (board[i][k] === "*") {
            break;
          }
        }
      }
    }
  }
  return board;
}

board = [
  [".", ".", "*", "#", "."],
  ["#", "#", ".", "*", "."],
  [".", ".", ".", ".", "*"],
  [".", ".", "*", ".", "#"],
  ["#", ".", "#", ".", "*"],
  [".", ".", ".", ".", "."],
];

console.log(solution(board));
