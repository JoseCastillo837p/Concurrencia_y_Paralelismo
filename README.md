# ⚡ Concurrencia y Paralelismo

## Ingeniería en Tecnologías de Software - 5to Semestre

### 📋 Descripción

Este repositorio contiene los materiales, ejercicios y proyectos desarrollados durante la unidad de aprendizaje **Concurrencia y Paralelismo**. El curso está diseñado para construir programas de cómputo que resuelven problemas lógico-computacionales mediante la aplicación de algoritmos concurrentes y/o con paralelismo, utilizando las características y técnicas de lenguajes de programación como Java y C++.

El objetivo es comprender y aplicar los principios fundamentales de la programación concurrente y paralela, desde la gestión de hilos y mecanismos de sincronización hasta su implementación en sistemas distribuidos, dispositivos móviles y entornos de cómputo en la nube.

---

### 🎯 Competencia de la Unidad

Construir programas de cómputo para resolver problemas lógico-computacionales que requieren de la aplicación de algoritmos concurrentes y/o con paralelismo, aplicando las características y técnicas de un lenguaje de programación.

---

### 📚 Temario

| Subcompetencia                                   | Temas                                                                                                                                                                                                                                                                                                                                   | Prácticas |
| ------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- |
| **1. Conceptos básicos**                         | 1.1 Definición de concurrencia<br>1.2 Definición de paralelismo<br>1.3 Definición de hilos<br>1.4 Desarrollo de programas con hilos                                                                                                                                                                                                     | -         |
| **2. Concurrencia**                              | 2.1 Procesos y concurrencia (estados, scheduler, intercalación)<br>2.2 Principio de exclusión mutua<br>2.3 Soluciones por hardware<br>2.4 Spinlocks (óptimos, equitativos, escalables)<br>2.5 Semáforos (definición, sincronización, interbloqueos)<br>2.6 Monitores (definición, variables de condición, algoritmos de sincronización) | P1, P2    |
| **3. Paralelismo**                               | 3.1 Modelado de computadores paralelos<br>3.2 Modelos de programación paralela (memoria compartida, paso de mensajes, SIMD)<br>3.3 Análisis de algoritmos paralelos<br>3.4 Metodologías de programación paralela<br>3.5 Entornos de programación (C, Java, otros)                                                                       | P3, P4    |
| **4. Desarrollo con concurrencia y paralelismo** | 4.1 Programación en servidores locales<br>4.2 Aplicaciones en sistemas distribuidos                                                                                                                                                                                                                                                     | P5, P6    |
| **5. Aplicaciones**                              | 5.1 Sistemas web<br>5.2 Dispositivos móviles<br>5.3 Big Data                                                                                                                                                                                                                                                                            | P6        |
| **6. Sistemas de supercómputo**                  | 6.1 Computadoras con multiprocesadores<br>6.2 Clusters (granjas de cómputo)<br>6.3 Programación en la nube                                                                                                                                                                                                                              | P8        |

---

### 🛠️ Tecnologías y Herramientas

- **Lenguajes:** Java (hilos, sincronización), C/C++ (pthreads, OpenMP, MPI)
- **Entornos de desarrollo:** Dev C++, Eclipse, NetBeans, IntelliJ IDEA
- **Paradigmas:** Programación concurrente, programación paralela, memoria compartida, paso de mensajes
- **Herramientas adicionales:** Git, sistemas de control de versiones

---

### 📖 Bibliografía Sugerida

**Básica:**

1. Muñoz, Escoí, Francisco Daniel, et al. _Concurrencia y sistemas distribuidos_. Editorial de la Universidad Politécnica de Valencia, 2013.
2. Almeida, Francisco, et al. _Introducción a la programación paralela_. Editorial Ediciones Paraninfo, S.A, 2008.

**Complementaria:**

1. Galli Granada, Ricardo. _Principios y algoritmos de concurrencia_. Createspace Independent Pub, 2015.
2. Vallejo, David, et al. _Programación concurrente y tiempo real_. 3ª edición, CreateSpace, 2015.
3. Alonso, José Miguel, y Alvarruz, Fernando. _Ejercicios de programación paralela con OpenMP y MPI_. Editorial de la Universidad Politécnica de Valencia, 2018.
4. Sánchez, Campos, Alberto, y Sánchez, Jesús Montes. _Programación de servicios y procesos_. RA-MA Editorial, 2014.
5. Domínguez, Mateos, Francisco, et al. _Programación multimedia y dispositivos móviles_. RA-MA Editorial, 2014.
6. Holmes, Dawn E. _Big Data: una breve introducción_. Antoni Bosch editor, 2018.
7. Celaya, Luna, Ainoa. _Cloud: herramientas para trabajar en la nube_. Editorial ICB, 2014.
8. Ordax, Cassá, José Miguel, y Ocaña Díaz Ufano, Pilar Aranzazu. _Programación web en java_. Ministerio de Educación de España, 2012.

---

### 📂 Estructura del Repositorio

```

└── README.md                   # Este archivo
```

### 👨‍🏫 Docente

**Ing. Sergio Andrés Noh Puch**  
📧 serganoh@uacam.mx

### 🔑 Conceptos Clave

- **Concurrencia:** Múltiples tareas progresan simultáneamente (pueden ejecutarse en un solo núcleo).
- **Paralelismo:** Múltiples tareas se ejecutan literalmente al mismo tiempo (requiere múltiples núcleos).
- **Hilos (Threads):** Unidad básica de ejecución dentro de un proceso.
- **Exclusión Mutua:** Mecanismo para evitar que múltiples hilos accedan simultáneamente a recursos compartidos.
- **Semáforos:** Mecanismo de sincronización que controla el acceso a recursos compartidos.
- **Monitores:** Constructores de sincronización que encapsulan recursos compartidos.
- **Spinlocks:** Mecanismo de bloqueo donde el hilo espera activamente en un bucle.
- **Interbloqueo (Deadlock):** Situación donde dos o más procesos se bloquean mutuamente.
- **Memoria Compartida:** Modelo de programación paralela donde los hilos comparten un espacio de memoria común.
- **Paso de Mensajes:** Modelo donde los procesos se comunican enviando mensajes.
- **Big Data:** Procesamiento de grandes volúmenes de datos que requiere técnicas de paralelismo.
- **Cloud Computing:** Infraestructura que permite el despliegue de aplicaciones concurrentes/paralelas a gran escala.
