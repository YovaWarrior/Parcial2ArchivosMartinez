#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>

namespace fs = std::filesystem;

int main() {
    int numbArch;
    std::cout << "¿Cuántos archivos deseas crear? ";
    std::cin >> numbArch;

    fs::path peque;

    if (numbArch % 2 == 0) { // Si es par
        fs::path par_dir = fs::path(getenv("USERPROFILE")) / "MisDocumentos" / "par";
        fs::create_directories(par_dir); // Crear la carpeta "par" si no existe

        for (int i = 1; i <= numbArch; i++) {
            fs::path file_path = par_dir / ("documento" + std::to_string(i) + ".txt");
            std::ofstream file(file_path);

            for (int j = 1; j <= i; j++) {
                file << "Línea " << j << " del documento " << i << std::endl;
            }

            file.close();

            if (i == 1 || fs::file_size(file_path) < fs::file_size(peque)) {
                peque = file_path;
            }
        }

        std::cout << "Se crearon " << numbArch << " archivos en " << par_dir << std::endl;
    }
    else { // Si es impar
        fs::path impar_dir = fs::path(getenv("USERPROFILE")) / "Escritorio" / "impar";
        fs::create_directories(impar_dir); // Crear la carpeta "impar" si no existe

        for (int i = 1; i <= numbArch; i++) {
            fs::path file_path = impar_dir / ("documento" + std::to_string(i) + ".txt");
            std::ofstream file(file_path);

            for (int j = 1; j <= i; j++) {
                file << "Línea " << j << " del documento " << i << std::endl;
            }

            file.close();

            if (i == 1 || fs::file_size(file_path) < fs::file_size(peque)) {
                peque = file_path;
            }
        }

        std::cout << "Se crearon " << numbArch << " archivos en " << impar_dir << std::endl;
    }

    std::cout << "El archivo más pequeño creado es: " << peque << std::endl;

    return 0;
}