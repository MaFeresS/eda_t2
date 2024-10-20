# eda_t2


Para compilar este programa, debe primero acceder a la carpeta 'build', creándola en caso de no existir. 
>>cd build
Si no existe:
>> mkdir build

>> cd build

Una vez dentro de build, debe hacer correr el cmake, lo que, entre otras cosas, creará un makefile. 
>> cmake ..

Una vez finalizada la creación del makefile, debe hacer correr make, manteniendose dentro de build. 
>> make

El make compilará los archivos y creará el programa imagepro, que se deberá correr desde el repositorio base. Para esto, debe salir de build y hacer correr el programa con ./build/imagepro. 
>> cd ..

>> ./build/imagepro
Este último paso es necesario para poder utilizar las imágenes guardadas en en la carpeta images.
-------------------------------------------------------------------------------------------------
En resumen, debe realizar, en orden, los siguientes comandos en la terminal desde el directorio base del repositorio para compilar correctamente el programa:

>> cd build

>> cmake ..

>> make

>> cd ..

>> ./build/imagepro
