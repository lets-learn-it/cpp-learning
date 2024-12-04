# Pascal's Triangle

![Pascal's triangle](./PascalTriangleAnimated.gif)

**Formula**

$$
\begin{aligned}
  {}^{n}C_{r} = \binom{R-1}{C-1} &= \frac{n!}{(n-r)! r!} \\
  &=
  \begin{cases}
    \frac{n \times (n-1) \times (n-2) \times ... \times (n-r-1)}{r!}  &\quad (n-r)  \geq r \\
    \frac{n \times (n-1) \times (n-2) \times ... \times (r-1)}{(n-r)!}  &\quad(n-r) < r
  \end{cases}
\end{aligned}
$$

**Examples**

$$
\begin{aligned}
  {}^{10}C_{3} &= \frac{10\times 9 \times 8}{3 \times 2 \times 1} \\
  {}^{5}C_{2} &= \frac{5 \times 4}{2 \times 1} \\
  {}^{4}C_{3} &= \frac{4}{1} \\
\end{aligned}
$$

## Case 1: Find element from $R^{th}$ row and $C^{th}$ column

$$
\begin{aligned}
  {}^{R-1}C_{C-1} &= \binom{R-1}{C-1} \\
  &= \frac{(R-1)!}{(R-C)! (C-1)!}   && \because {}^{n}C_{r} = \frac{n!}{(n-r)! r!}
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
