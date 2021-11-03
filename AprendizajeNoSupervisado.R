library(FactorMineR)

sewtd("")
Datos <- read.table('EjemploEstudiantes.csv', header = TRUE,  )
Datos

grupos = kmeans(Datos, 3, iter.max = 1000)
 
barplot(grupos$center[1, ] col = "blue") #centro de gravedad
barplot(grupos$center[1, ] col = "blue") #centro de gravedad
barplot(grupos$center[1, ] col = "blue") #centro de gravedad

rownames(grupos$centers)= c("cluster 1", "cluster 2", "cluster 3")
barplot(grupos$centers), beside = TRUE, col = heat.colors()

NDatos = cbind(Datos, grupos$centers)