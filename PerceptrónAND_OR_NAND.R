#NAND
#Valores aleatorios 
w1 = 1
w2 = 1
O = 1.5 

f <- function(x1, x2, w1, w2){
  (x1*w1+x2*w2 < O)
}
print("x1 = 0 x2 = 0")
f(0,0,w1,w2)
print("x1 = 0 x2 = 1")
f(0,1,w1,w2)
print("x1 = 1 x2 = 0")
f(1,0,w1,w2)
print("x1 = 1 x2 = 1")
f(1,1,w1,w2)

#OR
#Valores aleatorios 
w1 = 1
w2 = 1
O = 1.5 

f <- function(x1, x2, w1, w2){
  (x1*w1+x2*w2 > O)
}
print("x1 = 0 x2 = 0")
f(0,0,w1,w2)
print("x1 = 0 x2 = 1")
f(0,1,w1,w2)
print("x1 = 1 x2 = 0")
f(1,0,w1,w2)
print("x1 = 1 x2 = 1")
f(1,1,w1,w2)

#AND
#Valores aleatorios 
w1 = 1
w2 = 1
O = 1.5 

f <- function(x1, x2, w1, w2){
  (x1*w1+x2*w2 > O)
}
print("x1 = 0 x2 = 0")
f(0,0,w1,w2)
print("x1 = 0 x2 = 1")
f(0,1,w1,w2)
print("x1 = 1 x2 = 0")
f(1,0,w1,w2)
print("x1 = 1 x2 = 1")
f(1,1,w1,w2)

