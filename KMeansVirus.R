library(FactoMineR)
setwd("C:/Users/Montse/Downloads")
Datos <- read.csv('MutadosDataSet_EquipoNuevo2.csv', header = TRUE, sep=';', dec=',', row.names = 1)
dim(Datos)

grupos=kmeans(Datos, 2, iter.max = 100)  ##iter.max por defecto es 10
grupos

#Graficar los datos
barplot(grupos$center[1,], col="blue") ##centro de gravedad del cluster 1
barplot(grupos$center[2,], col="red") ##centro de gravedad del cluster 2

rownames(grupos$centers) = c("Cluster 1", "Cluster 2")

#En 'grupos'está a qué cluster pertenece cada fila de la tabla de datos

barplot(t(grupos$centers), beside = TRUE, col = heat.colors(5))
NDatos = cbind(Datos, Grupo=grupos$cluster)
NDatos
