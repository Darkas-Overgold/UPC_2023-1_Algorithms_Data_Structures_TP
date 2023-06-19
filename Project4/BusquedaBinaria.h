#pragma once
template<class T>
bool compararPorId(T reg1, T reg2) {
    return reg1->getId() < reg2->getId();
}
// Implementación de la función de búsqueda binaria por ID
template<class T>
T busquedaBinariaPorId(vector<T>& registros, int id) {
    int low = 0;
    int high = registros.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (registros[mid]->getId() == id) {
            return registros[mid];
        }
        else if (registros[mid]->getId() < id) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }


    return nullptr; // ID no encontrado
};