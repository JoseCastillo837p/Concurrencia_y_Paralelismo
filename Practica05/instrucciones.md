# Práctica: Medición de Speedup, Eficiencia y Overhead en Monte Carlo

##  Objetivo

Medir experimentalmente el rendimiento del cálculo de π por Monte Carlo con **1, 4 y 8 hilos**, calculando las métricas de **speedup**, **eficiencia** y **overhead**, y presentando los resultados en **gráficas comparativas**.

**Trabajo individual.**

---

##  Instrucciones

### 1. Punto de partida

Usa el programa de Monte Carlo con `pthreads` y semáforos (el que ya desarrollaste). Debe permitir indicar el **número de hilos** por línea de comandos y medir el **tiempo de ejecución**.

### 2. Elección de la carga de trabajo

- Selecciona **una cantidad de puntos aleatorios** que consideres adecuada.
- **Sugerencia**: usa al menos **100 millones de puntos** (100,000,000) para que el tiempo de ejecución sea lo bastante largo como para que las mediciones sean representativas. Con menos puntos, el *overhead* de creación de hilos puede dominar y distorsionar los resultados.
- **Importante**: la cantidad de puntos debe ser **la misma** en las tres ejecuciones (1, 4 y 8 hilos). Si no, las comparaciones no son válidas.

### 3. Ejecuciones a realizar

Realiza **tres ejecuciones**, cada una con la misma cantidad de puntos:

| Ejecución | Número de hilos |
|-----------|-----------------|
| 1 | 1 hilo |
| 2 | 4 hilos |
| 3 | 8 hilos |

**Recomendación práctica**: ejecuta cada configuración **al menos 3 veces** y toma el **promedio** de los tiempos. Esto reduce el ruido causado por el sistema operativo y otros procesos. Si no quieres complicarte, con una sola ejecución por configuración es suficiente para la práctica.

### 4. Registro de datos

Para cada ejecución, anota:

- **Número de hilos** (p)
- **Tiempo de ejecución** en segundos (T)
- **Tiempo secuencial** (T₁) = tiempo con 1 hilo

### 5. Cálculo de métricas

Con los datos anteriores, calcula para **4 y 8 hilos** (el caso de 1 hilo es la referencia):

**Speedup:**
```
S(p) = T(1) / T(p)
```

**Eficiencia:**
```
E(p) = S(p) / p
```

**Overhead:**
```
O(p) = p · T(p) − T(1)
```

Donde `p` es el número de hilos y `T(p)` el tiempo con `p` hilos.

### 6. Entregable: solo gráficas

El entregable consiste **únicamente en tres gráficas** (una por métrica), todas comparando los casos de 1, 4 y 8 hilos.

#### Gráfica 1: Tiempo de ejecución
- **Eje X**: número de hilos (1, 4, 8)
- **Eje Y**: tiempo en segundos
- Tipo: barras

#### Gráfica 2: Speedup
- **Eje X**: número de hilos (1, 4, 8)
- **Eje Y**: speedup
- Tipo: barras
- **Añade una línea de referencia** que represente el *speedup* ideal (lineal), para comparar visualmente.

#### Gráfica 3: Eficiencia y Overhead
- **Eje X**: número de hilos (1, 4, 8)
- **Eje Y izquierdo**: eficiencia (0 a 1 o 0% a 100%)
- **Eje Y derecho**: overhead en segundos
- Tipo: barras para eficiencia + línea para overhead (gráfica combinada)
- Si te resulta muy complejo, sepáralas en dos gráficas independientes.

### 7. Formato de las gráficas

- Cada gráfica debe tener **título**, **etiquetas en los ejes** y **leyenda** si aplica.
- Incluye los **valores numéricos** sobre cada barra o punto (por ejemplo, `S(4) = 3.5x`).
- Usa una herramienta simple: **Excel, Google Sheets, Python (matplotlib), Gnuplot** o similar.

### 8. Presentación

- Entrega las gráficas en un **solo documento** (PDF o presentación).
- Puedes incluir una **tabla resumen** con los datos crudos y las métricas calculadas, pero las gráficas son el elemento principal.

---

##  Entregables

1. **Gráfica de tiempo de ejecución** vs número de hilos.
2. **Gráfica de speedup** vs número de hilos (con línea de speedup ideal).
3. **Gráfica de eficiencia y overhead** vs número de hilos.
4. (Opcional) Tabla resumen con tiempos y métricas.

---

##  Criterios de evaluación

| Criterio | Peso sugerido |
|----------|---------------|
| Se usó la misma cantidad de puntos en las 3 ejecuciones | 15% |
| Las métricas fueron calculadas correctamente | 30% |
| Las gráficas son claras y comparables | 35% |
| Las gráficas están bien etiquetadas (títulos, ejes, valores) | 20% |

---

##  Consejos prácticos

- **No cambies la cantidad de puntos** entre ejecuciones; si lo haces, los resultados no se pueden comparar.
- Si el tiempo con 1 hilo es muy pequeño (menos de 1 segundo), los resultados serán ruidosos. Aumenta los puntos.
- Cierra otras aplicaciones pesadas antes de medir, para reducir el ruido del sistema.
- Ten en cuenta que si tu CPU tiene **menos de 8 núcleos físicos**, el speedup con 8 hilos será menor al ideal; eso **no es un error**, es precisamente lo que la práctica busca evidenciar.
- Si alguna gráfica sale "rara" (por ejemplo, speedup mayor que el número de hilos, o eficiencia mayor a 1), revisa tus mediciones: probablemente hubo ruido o un error en el cálculo.

---

##  Nota final

El objetivo de esta práctica **no es obtener números perfectos**, sino **observar experimentalmente** cómo se comporta el paralelismo en un problema real: el speedup no crece infinitamente, la eficiencia disminuye al agregar hilos, y aparece un overhead inevitable. Las gráficas deben contar esa historia.