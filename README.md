*Este proyecto ha sido creado como parte del currículo de 42 por <tide-oli>.*

# Descripción

Este proyecto implementa la función **get_next_line**, cuyo objetivo es leer una línea completa de un descriptor de archivo (`fd`) cada vez que se llama, sin importar el tamaño del buffer definido en tiempo de compilación.  

La función maneja:
- Lectura de archivos de cualquier tamaño.  
- Manejo de saltos de línea `\n` correctamente.  
- Memoria dinámica para almacenar líneas y el “stash” temporal de datos.  

Este proyecto tiene como objetivo profundizar en el manejo de memoria dinámica, punteros y funciones de manipulación de strings en C, cumpliendo con las normas de codificación de 42.

# Instrucciones

1. **Compilación:**  
   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=<tamaño> get_next_line.c get_next_line_utils.c get_next_line.h main.
