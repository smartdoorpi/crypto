#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long int
PrimeChecker (long long int n)
{
  long long int i;
  long long int m = sqrt(n);

  for (i = 2; i <= m; i++)
    {
      if (n % i == 0)
	{
	  return 0;
	}
    }

  return 1;	
}

long long int
findGCD (long long int n1, long long int n2)
{
  long long int i, gcd;

  for (i = 1; i <= n1 && i <= n2; ++i)
    {
      if (n1 % i == 0 && n2 % i == 0)
	gcd = i;
    }

  return gcd;
}

long long int
powMod (long long int a, long long int b, long long int n)
{
  long long x = 1, y = a;

  for (long long int j = 0; j < b; j++)
    {
      x = x * a;
      x = x % n;
    }
  return x;
}

long long int
findInv (long long int x, long long int y, long long int n)
{
  long long int d = 2, temp;

  while (d < n)
    {
      temp = ((d * x) - 1) % y;
      if (temp == 0)
	break;
      d++;
    }
  return d;
}

long long int
main (long long int argc, char *argv[])
{
  long long int p, q;
  long long int n, phin;

  long long int data, cipher, decrypt;

  while (1)
    {
      printf ("Enter any two prime numbers: ");
      scanf ("%lld %lld", &p, &q);

      if (!(PrimeChecker (p) && PrimeChecker (q)))
	printf
	  ("Entered numbers are not prime.Please enter prime numbers only...\n");
      else if (!PrimeChecker (p))
	printf
	  ("The first prime number you entered is not prime, please try again...\n");
      else if (!PrimeChecker (q))
	printf
	  ("The second prime number you entered is not prime, please try again...\n");
      else
	break;
    }

  printf ("Enter some numerical plaintext: ");
  scanf ("%lld", &data);

  n = p * q;

  phin = (p - 1) * (q - 1);

  long long int e = 0;
  for (e = 2; e <= phin; e++)
    {
      if (findGCD (phin, e) == 1)
	break;
    }

  long long int d = 0;
  for (d = e + 1; d <= phin; d++)
    {
      if (((d * e) % phin) == 1)
	break;
    }

  printf ("Value of e: %lld\nValue of d: %lld\n", e, d);

  clock_t start = clock ();
  cipher = powMod (data, e, n);
  printf ("\nThe cipher text is: %lld with excryption time: %f ms\n", cipher,
	  (double) (clock () - start) * 1000 / CLOCKS_PER_SEC);

  start = clock ();
  decrypt = powMod (cipher, d, n);
  printf ("\nThe decrypted text is: %lld with decryption time: %f ms\n",
	  decrypt, (double) (clock () - start) * 1000 / CLOCKS_PER_SEC);

  long long int dP = findInv (e, p - 1, n);
  long long int dQ = findInv (e, q - 1, n);
  long long int qInv = findInv (q, p, n);
  printf ("\nCRT(Chinese Remainder Theorem) Parameters are as below:\n");
  printf ("dP=%lld, dQ=%lld, qInv=%lld\n", dP, dQ, qInv);
  long long int m1 = 1;
  long long int m2 = 1;
  long long int k = 1;

  //printing original message
  start = clock ();
  for (long long int j = 1; j <= dP; j++)
    {
      m1 = (m1 * cipher) % p;
    }

  for (long long int j = 1; j <= dQ; j++)
    {
      m2 = (m2 * cipher) % q;
    }

  long long int h = (qInv * (m1 + p - m2)) % p;
  k = m2 + (h * q);
  printf
    ("\nThe decrypted text with CRT is: %lld and decryption time : %f ms\n\n",
     k, (double) (clock () - start) * 1000 / CLOCKS_PER_SEC);
  return 0;
}
