# Pascal's Triangle

![Pascal's triangle](./PascalTriangleAnimated.gif)

## Case 1: Find element from $R^{th}$ row and $C^{th}$ column

$$
\begin{aligned}
  {}^{R-1}C_{C-1} &= \binom{R-1}{C-1} \\
  &= \frac{(R-1)!}{(R-C)! (C-1)!}   && \because {}^{n}C_{r} = \frac{n!}{(n-r)! r!} \\
  {}^{10}C_{3} &= \frac{10*9*8}{3*2*1} \\
  {}^{5}C_{2} &= \frac{5*4}{2*1} \\
  {}^{4}C_{3} &= \frac{4}{1} \\
\end{aligned}
$$

## Case 2: Find $R^{th}$ row

$$
\begin{aligned}
  1st &= 1 \\
  2nd &= (1) * \frac{R-1}{1} \\
  3rd &= \left( \frac{R-1}{1} \right) * \frac{R-2}{2},  \\
  4th &= \left( \frac{R-1}{1} * \frac{R-2}{2} \right) * \frac{R-3}{3}, \\
      &= ..., \\
  Rth &= \left( \frac{R-1}{1} * \frac{R-2}{2} * \frac{R-3}{3} *... \right) * \frac{1}{R-1}
\end{aligned}
$$

## Case 3: Print complete pascal's triangle

- Find row by row.
