![Tec de Monterrey](images/logotecmty.png)

# Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

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

El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato.

```
<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>
```

Ejemplo:

```
03-01-20 13:45 M 8PAK7
```

Donde:

- El punto de entrada puede ser **M – Mar Mediterráneo** y **R – Mar Rojo**.
- La fecha estará entre **01-01-2020** y **31-12-2020**.
- El tiempo estará en formato de 24 Hrs.

En equipo, deberán hacer una aplicación que:

- Lea un archivo de entrada (ej. canal.txt), en el cual el primer renglon consiste del numero de registros a leer y el prefix a búscar. Después, se leen y alamacenan los registros en dos listas encadenadas, una para los que entran por el mar Mediterráneo y otra para los buques que entran por el mar Rojo.
- Ordene ambas listas encadenadas por Fecha + UBI (primero por fecha, al haber empate ordenar por UBI).
- Despliegue mes por mes (empezando por el primer mes que venga un buque de esa serie y terminando en el mes de la última entrada) la cantidad de entrada de buques de esa serie por cada una de las entradas con el siguiente formato:

```
<mes> <año> <cant-M> <cant-R>
```

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>

La primera línea de entrada contiene dos elementos: un entero _n_, el número de barcos que ha entrado al canal, y una cadena de 3 tres caracteres _prefix_, el prefijo del UBI a búscar. Las siguientes _n_ líneas; contiene el registro de los barcos que han entrado al canal con el formato descrito anteriormente. Todas las fechas

## <span style="color: rgb(26, 99, 169);">**Salida**</span>

Deberás desplegar el listas por mes de los buques cuyo UBI empiece con _prefix_ hayan entrada por el mar Mediterráneo, así como el listado de los que entraron por el mar Rojo. Se deben omitir los meses en los que no haya entrado ningún barco por ambas entradas o aquella entrada por la que no haya ingresado algún barco en un mes en particular.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>

```
27 2FJ
25-07-20 20:10 M 2FJU9
05-01-20 10:16 M 1FRB6
17-07-20 21:36 R 2FRZ9
17-10-20 10:06 M 2TLR2
24-04-20 14:15 M 2FJA8
18-08-20 14:50 M 2ARL4
19-11-20 07:08 M 2OIM0
10-09-20 14:02 R 1TLP1
24-05-20 12:36 M 2ARF7
13-12-20 19:59 M 2MXB0
05-10-20 17:04 R 2UYN7
05-10-20 03:47 R 1AVM9
13-04-20 12:29 M 1MXL3
29-07-20 11:09 M 2ARA4
04-10-20 14:32 R 1ARY0
24-10-20 20:34 R 1ARU2
25-04-20 21:28 M 2TLP1
09-01-20 07:37 M 2FJX8
28-09-20 20:22 M 2MXJ6
12-10-20 10:28 R 1IJH1
20-11-20 13:37 R 1MXT7
30-10-20 12:52 M 1FRD9
27-01-20 16:36 M 1FRB7
07-02-20 00:21 M 2FJV6
17-11-20 05:45 M 2ARF4
01-02-20 01:55 R 2FJB6
14-03-20 16:13 M 1MXU2
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>

```
jan
M 1: 2FJX8
feb
M 1: 2FJV6
R 1: 2FJB6
apr
M 1: 2FJA8
jul
M 1: 2FJU9
```

Para probar tu implementación, compila tu programa con el comando:

```
make
```

Si quieres probar únicamente un test en particular, ejecuta el comando respectivo:

```
make testX
```

donde X representa el cnumero correspondiente a uno de los 4 tests.

Recuerda actualizar tu repositorio (_git push_) a lo largo del desarrollo de la actividad.

Por último, realiza en forma individual una investigación y reflexión de la importancia y eficiencia del uso de listas encadenas en una situación problema de esta naturaleza, generando un documento llamado **ReflexAct23_A0XXXX.pdf**.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **70%** - Se realiza la implementación de la manera especificada. Para cada una de las funcionalidades se evaluará:

  - **Excelente (70%)** - Pasa correctamente todos los casos de prueba.
  - **Muy bien (55%)** - Pasa correctamente el 75% de los casos de prueba.
  - **Bien (35%)** - Pasa correctamente el 50% de los casos de prueba.
  - **Insuficiente (20%)** - Pasa correctamente menos del 50% de los casos de prueba.

- **20%** - El documento de reflexión deberá incluir de manera específica si el uso de un lista doblemente ligada para esta situación problema es la más adecuada o no así como sus ventajas y desventajas, así como la complejidad computacional para las operaciones solicitadas.
- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>

Esta actividad forma parte tanto de tu calificación final del curso, así como del portafolio de evidencias de las competencias a desarrollar del curso, por lo que se te pide que en forma individual:

- Realices una entrega del código fuente de la solución del problema, en la sección correspondiente dentro de esta plataforma, así como el documento de reflexión individual (**ReflexAct23_A0XXXX.pdf**).
  En la carpeta personal llamada **TC1031(Portafolio_Final)** que generaste desde la entrega de la actividad 1.3 y que te servirá como preparación para la entrega del portafolio de competencias que se realizará al final del curso, coloca en la subcarpeta **Act23** tus archivos que solucionaron la <span style="text-decoration: underline;">actividad 2.3</span> así como el documento de reflexión individual (**ReflexAct23_A0XXXX.pdf**).
