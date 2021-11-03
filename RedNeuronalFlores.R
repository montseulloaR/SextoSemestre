library(nnet)
#leer datos
setwd(" /*direccion*/ ")
datos <- read.csc("iris.csv", sep = ";", dec = ".", header = T)
datos

#Segmenta el data set
muestra <- sample(1:150, 50)
muestra

#tabla de evaluacion
ttesting <- datos[muestra]

#tabla de entrenamiento
taprendizaje <- datos[-muestra,]
taprendizaje

#entrena el modelo
modelo <- nnet(tipo~., data = taprendizaje, size = 4, rang = 0.1)
modelo

#prediccion o clasificacion
prediccion <- predict(modelo, ttesting[,-5], type="class")
prediccion

#evaluar modelo
MC <- table(ttesting$tipo, prediccion)
MC
acierto <-sum(diag(MC)/sum(MC))
acierto
error <- 1-acierto
error