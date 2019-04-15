## 注意事项

- 需要考虑base=0, exponent<=0的情况
<br>

- 在比较两个浮点数的时候，不能直接用==, 因为计算机有的时候表示float double的时候有误差




## 优化

- 对于方法２求普通次方，运用了递归：比如求$ 2^{10} $
1. 方法一乘以base 10次
2. 方法二，$ 2^{10} $可以分成$ 2^5\times2^5 $, $ 2^5 $可以分成$ 2^2\times2^2\times $base, 利用公式:
$$ a^n= $$


<a href="https://www.codecogs.com/eqnedit.php?latex=ax^{2}&space;&plus;&space;by^{2}&space;&plus;&space;c&space;=&space;0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?ax^{2}&space;&plus;&space;by^{2}&space;&plus;&space;c&space;=&space;0" title="ax^{2} + by^{2} + c = 0" /></a>
