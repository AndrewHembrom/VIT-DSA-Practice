# Implement  polynomial  addition  using singly  linked  list  data  structure[CO1,C02]

## Create the class Polynomial with the following functions (10 Marks)
**Note: add new functions to the class if required.**
- read() –read polynomial(coefficient and power)from the user.
- display(poly) –displays the polynomial in the format.[coeff,power->coeff,power->.......->coeff,power]
- addPolynomial(poly1, poly2) –adds two polynomials poly1, poly2

### Testcases
1) **Test Case 1:**
    - Poly1: 3x7+8x3 +7x2+9
    - Poly2: 7x3+6x1+6
    - Resultant Poly: 3x7+15x3+7x2+6x1+15
    - Expected Output 3,7->15,3->7,2->6,1->15,0

2) **Test Case 2:**
    - Poly1: 10x2+5x1
    - Poly2: 7x2+9x1
    - Resultant Poly: 17x2+14x1
    - Expected Output: 17,2->14,1

3) **Test Case 3:**
    - Poly1:2x5+45x3+26x1
    - Poly2:62x4+8x2+88
    - Resultant Poly: 2x5+62x4+45x3+8x2+26x1+88
    - Expected Output: 2,5->62,4->45,3->8,2->26,1->88,0
