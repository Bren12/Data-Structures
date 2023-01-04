![Tec de Monterrey](images/logotecmty.png)

# Act 3.4 - Actividad Integral de Árboles (Evidencia Competencia)

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

- Lea un archivo de entrada (ej. canal.txt), en el cual el primer renglon consiste del numero de registros a leer. Después, se leen y contabilizan el número de incidencias de cada una de las series (los primeros tres caracteres del UBI). Las series y el número de incidencias se deberan guardar en dos árboles binarios de búsqueda, uno para las series de buques que entraron por el mar Mediterráneo y otro para las series que entraron por el mar Rojo.
- Despliegue los prefix que tienen un mínimo de 10 incidencias en forma descendiente, donde la prioridad esta dada por el número de incidencias de cada prefix (a mayor incidencias mayor proridad). El resultado se deberá de desplegar en el siguiente formato:

```
Mar Rojo
<prefix> <cantidad>
.
.
.
Mar Mediterráneo
<prefix> <cantidad>
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

Por último, realiza una investigación y reflexión de la importancia y eficiencia del uso de BST en una situación problema de esta naturaleza, generando un documento llamado **"ReflexAct34_A0XXXXX.pdf"**

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **70%** - Para cada una de las funcionalidades se evaluará:

  - **Excelente (70%)** - pasa correctamente todos los casos de prueba.
  - **Muy Bien (52%)** - pasa correctamente el 75% de los casos de prueba.
  - **Bien (35%)** - pasa correctamente el 50% de los casos de prueba.
  - **Insuficiente (17%)** - pasa correctamente menos del 50% de los casos de prueba.

- **20%** - El documento de reflexión de la importancia y eficiencia del uso de BST en una situación problema de esta naturaleza.
- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
