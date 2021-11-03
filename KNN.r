##install.packages("kknn", dependencies=TRUE)
library(kknn)
setwd("C:/Users/andyd/OneDrive/Documentos/Andrea/6° Semestre/Aprendizaje Inteligente")
rm(list=ls(all=TRUE))
datos<-read.csv("iris.csv", sep=";" ,dec='.', header=T)
suppressMessages(library(kknn))
dim(datos)
head (datos)
##Generar al azar una tabla de prueba

muestra <- sample(1:150,50)
muestra
ttesting <- datos[muestra,]
taprendizaje <- datos[-muestra,]
taprendizaje

##train.kknn

modelo <- train.kknn(tipo~.,data=taprendizaje,kmax=9)
modelo

prediccion<-predict(modelo,ttesting[,-5])
prediccion
##Matriz de confusion

MC<-table(ttesting[,5],prediccion)
MC
##Porcentaje de buena clasificación

acierto<-(sum(diag(MC)))/sum(MC)
acierto
error<-1-acierto
error