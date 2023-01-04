![Tec de Monterrey](images/logotecmty.png)
# Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás archivos de entrada, así como las salidas esperadas que podrás usar para probar tu implementación. También encontrarás un archivo "main.cpp". Ahí deberás implementar tu solución. En el archivo deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```
<span style="text-decoration: underline;">De manera individual</span>, desarrolla la solución del siguiente problema:

El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato:
```
<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>
```
Ejemplo:
```
03-01-20 13:45 M 8PAK7
```
Donde:
* El punto de entrada puede ser **M – Mar Mediterráneo** y **R – Mar Rojo**.
* La fecha estará entre **01-ENE-2020** y **31-DIC-2020**.
* El tiempo estará en formato de 24 Hrs.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
La primera línea de entrada contiene dos elementos: un entero *n*, el número de barcos que ha entrado al canal, y una cadena de 3 tres caracteres *prefix*, el prefijo del UBI a búscar. Las siguientes *n* líneas; contiene el registro de los barcos que han entrado al canal con el formato descrito anteriormente.

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
Deberás desplegar sólo los registros cuyo UBI empiece con *prefix*, ordenados por fecha.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
```
16 2HU
01-01-20 00:17 R 2HUN5
01-01-20 00:37 R 2AET2
01-01-20 00:57 M 2HUQ5
01-01-20 01:17 M 2FRW0
01-01-20 01:37 M 4MXV8
01-01-20 01:57 R 2HUG7
01-01-20 02:17 R 1KIH9
01-01-20 02:37 R 2HUX2
01-01-20 02:57 M 3CFE2
01-01-20 03:17 R 1TLD0
01-01-20 03:37 R 3FRF4
01-01-20 03:57 R 2HUK8
01-01-20 04:17 M 0CFR7
01-01-20 04:37 R 0TQL9
01-01-20 04:57 R 2HUS4
01-01-20 05:17 R 0FRX0
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
```
01-01-20 00:17 R 2HUN5
01-01-20 00:57 M 2HUQ5
01-01-20 01:57 R 2HUG7
01-01-20 02:37 R 2HUX2
01-01-20 03:57 R 2HUK8
01-01-20 04:57 R 2HUS4
```

Para probar tu implementación, compila tu programa con el comando:
```
make
```
Si quieres probar únicamente un test, ejecuta el comando respectivo:
```
make test1
```
```
make test2
```
```
make test3
```
```
make test4
```
Por último, realiza en forma individual una investigación y reflexión de la importancia y eficiencia del uso de grafos en una situación problema de esta naturaleza,  generando un documento llamado **"ReflexAct1.3.pdf "**.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **70%** - Cumple correctamente con la funcionalidad requerida por parte de la actividad:

    - **10%** - Lectura de datos del archivo correspondiente.
    - **20%** - Ordena los datos correctamente.
    - **20%** - Realiza correctamente la búsqueda de información.
    - **20%** - Despliega los dato en forma descendente por cantidad de accesos. 

- 20% - El documento de reflexión incluye la explicación de los algoritmos de ordenamiento y búsqueda implementados para esta situación problema, así como la complejidad computacional de cada uno de ellos.
- 10% - El código deberá seguir los lineamientos estipulados en el estándar de codificación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Esta actividad forma parte tanto de tu calificación final del curso, así como del portafolio de evidencias de las competencias a desarrollar del curso, por lo que se te pide que en forma individual:
* Cada integrante del equipo subirá en este repositorio su documento de reflexión final (**ReflexAct1.3.pdf**), el cual se realiza de manera individual.
