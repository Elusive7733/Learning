const checkPrime = (num) => {
  let isPrime = true;

  if (num === 1 || num === 0) {
    isPrime = false;
  } else if (num !== 2) {
    for (let i = 2; i < num; i++) {
      if (num % i === 0) {
        isPrime = false;
        break;
      }
    }
  }
  return isPrime;
};

const printPrime = (n) => {
  for (let i = 0; i <= n; i++) {
    if (checkPrime(i)) {
      console.log(i);
    }
  }
};

printPrime(17);
