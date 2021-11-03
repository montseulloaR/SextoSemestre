
library(e1071)

setwd("C:/Users/Montse/Downloads")
datos<-read.table("VirusDataSet_EquipoNuevo.csv",header=TRUE, sep=";" ,dec=',')
dim(datos)
head (datos)
mutados<-read.table("MutadosDataSet_EquipoNuevo.csv",header=TRUE, sep=";" ,dec=',')

##Generar la tabla de prueba
muestra <- c(90:113) #Receptores mutados
todos <- c(1:83) #Receptores para entrenar
mutado <- c(1:31) #Receptores para probar

ttodos <-datos[todos,] #Tabla de datos de receptores para entrenar
ttodos
tmutados <-mutados[mutado,] #Tabla de datos de receptores mutados
tmutados
ttesting <- datos[muestra,] #Tabla de datos de receptores para probar
ttesting

##train.naiveBayes
modelo <- naiveBayes(Receptor~.,data=ttodos) ##Implementa el naiveBayes que ya está cargado en la librería
modelo

prueba <-predict(modelo,ttesting[,-6]) #Prediccion con los datos para revisar
prueba
  
matrizP <- table(ttesting[,6],prueba) #Revision
matrizP

#ttesting[,6] <- prediccion
#ttesting

prediccion <-predict(modelo, tmutados[,-6]) #Prediccion con los datos mutados
prediccion

matrizX <- table(tmutados[,1],prediccion) #Revision
matrizX

