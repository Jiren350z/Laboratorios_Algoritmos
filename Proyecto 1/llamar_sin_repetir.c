/*
llamar sin repetir
Guardian *llamar_azar_sin_repetir(Guardian *headRef, int *llamados, int *contador) {
    int total_jugadores = 0;
    jugador *jugador_actual = primer_jugador;
    while (jugador_actual != NULL) {
        total_jugadores++;
        jugador_actual = jugador_actual->siguiente;
    }
    int numero_aleatorio = rand() % total_jugadores + 1;
    jugador_actual = primer_jugador;
    for (int i = 1; i < numero_aleatorio; i++) {
        jugador_actual = jugador_actual->siguiente;
    }
    while (llamados[jugador_actual - primer_jugador]) { // verificar si el jugador ya fue llamado antes
        numero_aleatorio = rand() % total_jugadores + 1;
        jugador_actual = primer_jugador;
        for (int i = 1; i < numero_aleatorio; i++) {
            jugador_actual = jugador_actual->siguiente;
        }
    }
    llamados[jugador_actual - primer_jugador] = 1; // marcar al jugador como llamado
    (*contador)++; // aumentar el contador de jugadores llamados
    return jugador_actual;
}  









jugador *llamar_jugador_al_azar(jugador *primer_jugador, int *jugadores_disponibles, int total_jugadores_disponibles) {
    int numero_aleatorio = rand() % total_jugadores_disponibles;
    jugador *jugador_actual = primer_jugador;
    for (int i = 0; i < numero_aleatorio; i++) {
        jugador_actual = jugador_actual->siguiente;
    }
    while (jugadores_disponibles[numero_aleatorio] == 0) {
        numero_aleatorio = (numero_aleatorio + 1) % total_jugadores_disponibles;
        jugador_actual = primer_jugador;
        for (int i = 0; i < numero_aleatorio; i++) {
            jugador_actual = jugador_actual->siguiente;
        }
    }
    jugadores_disponibles[numero_aleatorio] = 0;
    return jugador_actual;
}

jugador *llamar_jugador_al_azar(jugador *primer_jugador, int *jugadores_disponibles, int total_jugadores_disponibles) {
    int numero_aleatorio = rand() % total_jugadores_disponibles;
    jugador *jugador_actual = primer_jugador;
    for (int i = 0; i < numero_aleatorio; i++) {
        jugador_actual = jugador_actual->siguiente;
    }
    while (jugadores_disponibles[numero_aleatorio] == 0) {
        numero_aleatorio = (numero_aleatorio + 1) % total_jugadores_disponibles;
        jugador_actual = primer_jugador;
        for (int i = 0; i < numero_aleatorio; i++) {
            jugador_actual = jugador_actual->siguiente;
        }
    }
    jugadores_disponibles[numero_aleatorio] = 0;
    return jugador_actual;
}


jugador *llamar_jugador_al_azar_sin_repetir(jugador *primer_jugador) {
    int total_jugadores = 0;
    jugador *jugador_actual = primer_jugador;
    while (jugador_actual != NULL) {
        total_jugadores++;
        jugador_actual = jugador_actual->siguiente;
    }
    int llamado = 0;
    jugador_actual = primer_jugador;
    while (!llamado) {
        int numero_aleatorio = rand() % total_jugadores + 1;
        jugador_actual = primer_jugador;
        for (int i = 1; i < numero_aleatorio; i++) {
            jugador_actual = jugador_actual->siguiente;
        }
        if (!jugador_actual->llamado) {
            jugador_actual->llamado = 1;
            llamado = 1;
        }
    }
    return jugador_actual;
}



while (jugador_repetido) {
        jugador_repetido = 0;
        jugador *jugador_anterior = NULL;
        jugador *jugador_temporal = primer_jugador;
        while (jugador_temporal != jugador_actual) {
            if (strcmp(jugador_temporal->nombre, jugador_actual->nombre) == 0) {
                jugador_repetido = 1;
                break;
            }
            jugador_anterior = jugador_temporal;
            jugador_temporal = jugador_temporal->siguiente;
        }
        if (jugador_repetido) {
            numero_aleatorio = rand() % total_jug












jugador *llamar_jugador_al_azar(jugador *primer_jugador, int *jugadores_seleccionados, int *total_jugadores_seleccionados) {
    int total_jugadores = 0;
    jugador *jugador_actual = primer_jugador;
    while (jugador_actual != NULL) {
        total_jugadores++;
        jugador_actual = jugador_actual->siguiente;
    }
    int numero_aleatorio = rand() % total_jugadores + 1;
    int jugador_seleccionado = -1;
    jugador_actual = primer_jugador;
    for (int i = 1; i <= total_jugadores; i++) 
	{
        if (jugadores_seleccionados[i] == 0) 
		{
            jugador_seleccionado++;
            if (jugador_seleccionado == numero_aleatorio - 1) 
			{
                jugadores_seleccionados[i] = 1;
                total_jugadores_seleccionados++;
                return jugador_actual;
            }
        }
        jugador_actual = jugador_actual->siguiente;
    }
    return NULL;
}











*/
