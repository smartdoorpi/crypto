1.Compile using g++ EEC.cpp -lstdc++
2. Run using ./a.out


Example:
kumari@kumari-linux:/local/mnt/workspace/kumari/Mtech/crypto/Assign_5$ g++ ElgamalEllipticCurve.cpp -lstdc++
kumari@kumari-linux:/local/mnt/workspace/kumari/Mtech/crypto/Assign_5$ ./a.out


Assignemet 5 - ElGamal Elliptic Curve Cryptography

Elliptic Curve General Form      y^2 mod p = (x^3  + A*x + B) mod p
Enter the value of P:
23

Enter the Value of a:
44

Enter the Value of b:
56

Current Elliptic Curve           ---> y^2 mod 23 = (x^3  + 44*x + 56) mod p



Generated Points are:
1       ( 1 , 3 )
2       ( 1 , 20 )
3       ( 3 , 10 )
4       ( 3 , 13 )
5       ( 8 , 0 )
6       ( 9 , 10 )
7       ( 9 , 13 )
8       ( 10 , 1 )
9       ( 10 , 22 )
10      ( 11 , 10 )
11      ( 11 , 13 )
12      ( 12 , 9 )
13      ( 12 , 14 )
14      ( 14 , 9 )
15      ( 14 , 14 )
16      ( 16 , 7 )
17      ( 16 , 16 )
18      ( 17 , 6 )
19      ( 17 , 17 )
20      ( 19 , 0 )
21      ( 20 , 9 )
22      ( 20 , 14 )
23      ( 21 , 11 )
24      ( 21 , 12 )
Base Point: (1,3)
Enter the random number 'd' i.e. Private key of Sender  (d<n)
5678
Enter the random number 'k' (k<n)
345
Enter the message to be sent:
7654
The message to be sent is:
7654
Value of C1: (345,1035)
Value of C2: (1966564,5884384)
The message received is:
34567