## 注意事项

- 需要考虑base=0, exponent<=0的情况
<br>

- 在比较两个浮点数的时候，不能直接用==, 因为计算机有的时候表示float double的时候有误差




## 优化

- 利用 exponent & 0x1==1 位运算来判断exponent是否为奇数还是偶数
- 利用 exponent >> 1 来实现 /2

- 对于方法２求普通次方，运用了递归：比如求 2^10
2^10 可以分成 2^5*2^5 ,  2^5 可以分成 2^2 * 2^2 * base, 利用公式:

<img src="https://latex.codecogs.com/gif.latex?\LARGE&space;a^n=\left&space;\{&space;^{a^{n/2}\times&space;a^{n/2}&space;\quad&space;\quad&space;\quad&space;\quad&space;\&space;if&space;\;&space;n&space;\;&space;is&space;\;&space;even}&space;_{a^{(n-1)/2}&space;\times&space;a^{(n-1)/2}&space;\times&space;a&space;\quad&space;if&space;\;&space;n&space;\;&space;is\;odd}" title="\LARGE a^n=\left \{ ^{a^{n/2}\times a^{n/2} \quad \quad \quad \quad \ if \; n \; is \; even} _{a^{(n-1)/2} \times a^{(n-1)/2} \times a \quad if \; n \; is\;odd}" />


