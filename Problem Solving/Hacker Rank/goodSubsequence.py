

def countGoodSubsequences(word):
    if not word:
        return 0

    subsequences = []
    for i in range(len(word)):
        for j in range(i + 1, len(word) + 1):
            subsequences.append(word[i:j])

    # Count the number of good subsequences
    good_subsequences = 0
    for subsequence in subsequences:
        if subsequence not in word:
            good_subsequences += 1

    print(subsequences)

if __name__ == '__main__':

    countGoodSubsequences("abca")