def find_prime_factors(number):
    """Find and print all prime factors of a positive integer."""
    # Sieve of Eratosthenes to find primes up to number
    prime = [True] * (number + 1)
    prime[0] = prime[1] = False

    i = 2
    while i * i <= number:
        if prime[i]:
            for j in range(i * 2, number + 1, i):
                prime[j] = False
        i += 1

    first_print = True
    for i in range(2, number + 1):
        if prime[i] and number % i == 0:
            if not first_print:
                print(" ", end="")
            print(i, end="")
            first_print = False


def main():
    n = int(input().strip())
    find_prime_factors(n)


if __name__ == "__main__":
    main()
