# 向量的导数

标签（空格分隔）： ML

---

## 向量对向量的导数
- $ A $为$ m \times n $的矩阵，$ \vec{x} $为$ n \times 1 $的向量，则$ A\vec{x} $为$ m \times 1 $的列向量，记$ \vec{y} = A\vec{x} $，则$ \frac{\partial\vec{y}}{\partial\vec{x}} = A^T $。
- 推导
令:
$ A = \begin{bmatrix}a\_{11} & a\_{12} & ... & a\_{1n}\\ a\_{21} & a\_{22} & ... & a\_{2n}\\ ... \\ a\_{m1} & a\_{m2} & ... & a\_{mn} \end{bmatrix}$，$ \vec{x} = \begin{bmatrix}x\_1\\ x\_2\\ x\_3 \end{bmatrix} $
则有:
$ A\vec{x} = \begin{bmatrix} a\_{11}x\_1+a\_{12}x\_2+...+a\_{1n}x\_n\\ a\_{21}x\_1+a\_{22}x\_2+...+a\_{2n}x\_n\\ ...\\ a\_{m1}x\_1+a\_{m2}x\_2+...+a\_{mn}x\_n \end{bmatrix} $
从而:
$ \frac{\partial A\vec{x}}{\partial\vec{x}} = \begin{bmatrix}a\_{11} & a\_{21} & ... & a\_{m1}\\ a\_{12} & a\_{22} & ... & a\_{m2}\\ ... \\ a\_{1n} & a\_{2n} & ... & a\_{mn} \end{bmatrix} = A^T$
- 结论推广
$ \frac{\partial A\vec{x}}{\partial\vec{x}} = A^T $
$ \frac{\partial A\vec{x}}{\partial\vec{x}^T} = A $
$ \frac{\partial\vec{x}^TA}{\partial\vec{x}} = A $

## 标量对向量的导数
- $ A $为$ m \times n $的矩阵，$ \vec{x} $为$ n \times 1 $的向量，记$ y = \vec{x}^TA\vec{x} $，则$ \frac{\partial y}{\partial\vec{x}} = (A^T+A)\vec{x} $。
- 特别的，若A为对称阵，则有$ \frac{\partial y}{\partial\vec{x}} = 2A\vec{x} $
