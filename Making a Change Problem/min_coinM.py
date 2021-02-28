infinity = 1000


def min_coin(w, coin):
    m = [0 for i in range(0, w + 1)]
    n = len(coin)
    for i in range(1, w + 1):
        minvalue = infinity
        for j in range(0, n):
            if coin[j] <= i:
                minvalue = min(minvalue, m[i - coin[j]])
                m[i] = 1 + minvalue
    return m[w]


if __name__ == '__main__':
    print("\nMinimum making a change problem\n")
    a = input("\nEnter Totle value\t")
    w = int(a)
    # coins
    coin = input("\nEnter coins\t")
    coin = coin.split()
    coin = [int(i) for i in coin]
    n = len(coin)
    print("\nMinimum number of coin =\t", min_coin(w, coin))
    # Time_Complexity O(w*n)
    Time_complexity = w * n
    print("\nTime Complexity O(w*n) =\t", Time_complexity)
    # Auxillary_Space O(n)
    auxillary_space = n
    print("\n Auxillary space O(n) =\t", auxillary_space)
