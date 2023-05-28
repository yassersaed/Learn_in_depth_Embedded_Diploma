#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(Register,Pin)       (Register |=(1<<Pin))
#define CLEAR_BIT(Register,Pin)     (Register &=~(1<<Pin))


#endif /* BIT_MATH_H_ */