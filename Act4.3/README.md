![Tec de Monterrey](images/logotecmty.png)

# Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>

En este repositorio encontrarás los archivos de entrada, así como las salidas esperadas que podrás usar para probar tu implementación. También encontrarás un archivo "main.cpp". Ahí deberás implementar tu solución. En el archivo deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:

```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```

<span style="text-decoration: underline;">De manera individual</span>, desarrolla la solución del siguiente problema:

Para evitar el problema que se tuvo en el Canal de Suez, la compañía naviera "International Seas, LTD." ha determinado que cada carguero tendrá un máximo número de puertos (MNP). Este número indica la cantidad de puertos en los cuáles un carguero puede atracar antes de tener que recorrer la ruta en sentido contrario. Cada vez que la nave atraca en un puerto, disminuye el MNP en 1. Si el valor de MNP llega a cero, el carguero tendrá que "girar" y recorrer su ruta en sentido inverso. Dada de una red de puertos, un puerto inicial de un carguero y un valor MNP, deberás determinar la cantidad de puertos que no van a poder ser visitados por ese carguero.

<p style="text-align: center;">
<img src="images/graph.png" alt="graph" style="width:500px;"/>
</p>

Toma con ejemplo la red anterior. Si un carguero con MNP de 2 saliera del puerto de Busan, sólo podría llegar a los puertos Yantai, Haikou, Singopore, Mersin, Taipei, Fuzhou, Zhuhai. No podría alcanzar ningún otro puerto, ya que el MNP se habría reducido a cero al llegar a los puertos Haikou, Fuzhou, Merson y Zhuhai. Si aumentamos el valor inicial MNP a 3, saliendo del puerto Busan, se podría llegar a todos los puertos excepto a Karachi y London.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>

Cada entrada tendrá el siguiente formato. Empieza con un número entero, _NC_, que especifica el número de conexiones entre los puertos de la red. Después, habrá _NC_ pares de nombres de puertos. Estos pares identifican los puertos que están conectados por una ruta de navegación. No habrá más que una ruta de navegación directa entre cualquier par de puertos y ninguna red contendrá más de 30 puertos. Después de la descripción de la red, habrá un número entero, _NQ_, que especifica el número de consultas que se realizarán. A continuación, habrá _NQ_ líneas conteniendo el nombre del puerto de inicio y el MNP inicial.

## <span style="color: rgb(26, 99, 169);">**Salida**</span>

Para cada consulta, muestra una sola línea que indica el número de caso de prueba (numerados secuencialmente desde uno), el número de puertos a los cuales no se puede llegar, el nombre del puerto inicial y el valor inicial de MNP. A continuación encontrarás un ejemplo de entrada y salida.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>

16 <br>
Alexandria Algeciras <br>
Algeciras Ambarli <br>
Ambarli Antwerp <br>
Alexandria Balboa <br>
Balboa Bandar <br>
Bandar Barcelona <br>
Antwerp Bremen <br>
Bremen Busan <br>
Algeciras Cai_Mep <br>
Cai_Mep Callao <br>
Ambarli Cartagena <br>
Barcelona Callao <br>
Cai_Mep Cartagena <br>
Callao Charleston <br>
Cartagena Charleston <br>
Charleston Busan <br>
2 <br>
Cai_Mep 2 <br>
Cai_Mep 3 <br>

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>

Case 1: 5 ports not reachable from port Cai_Mep with MNP = 2. <br>
Case 2: 1 ports not reachable from port Cai_Mep with MNP = 3. <br>

Para probar tu implementación, compila tu programa con el comando:

```
make
```

Para probar cada uno de los archivos de entrada de prueba que encontrarás en este repositorio (input1.txt, input2.txt, input3.txt, input4.txt), puedes realizar las pruebas individualmente con el comando _make testX_. Por ejemplo, para realizar el test 1 utiliza el comando:

```
make test1
```

Recuerda actualizar tu repositorio (_git push_) cuando hayas terminado tu implementación.

Por último, Realiza en forma individual una investigación y reflexión de la importancia y eficiencia del uso de grafos en una situación problema de esta naturaleza, generando un documento llamado **"ReflexAct4_A0XXXXX.3.pdf "**. Este documento deberá incluir el análisis de la complejidad computacional de los algoritmos implementados.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>
- **70%** - Cumple correctamente con la funcionalidad requerida por parte de la actividad:
  - **70%** - Pasa correctamente todos los casos de prueba.
  - **52%** - Pasa correctamente al menos el 75% de los casos de prueba.
  - **35%** - Pasa correctamente al menos el 50% de los casos de prueba.
  - **17%** - Pasa correctamente el 25% o menos de los casos de prueba.
- **20%** - El documento de reflexión de la importancia y eficiencia del uso grafos en una situación problema de esta naturaleza, así como la complejidad computacional para las operaciones implementadas.
- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>

Esta actividad forma parte tanto de tu calificación final del curso, así como del portafolio de evidencias de las competencias a desarrollar del curso, por lo que se te pide que en forma individual:

- Realices una entrega del código fuente de la solución del problema, en la sección correspondiente dentro de esta plataforma, así como el documento de reflexión individual (**ReflexAct4.3.pdf**).
  En la carpeta personal llamada **TC1031(Portafolio_Final)** que generaste desde la entrega de la actividad 1.3 y que te servirá como preparación para la entrega del portafolio de competencias que se realizará al final del curso, coloca en la subcarpeta **Act4.3** tus archivos que solucionaron la <span style="text-decoration: underline;">actividad 4.3</span> así como el documento de reflexión individual (**ReflexAct4.3.pdf**) .
