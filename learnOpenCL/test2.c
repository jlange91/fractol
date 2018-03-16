#include <stdlib.h> #include <stdio.h> #include "CL/opencl.h"
#define QTE_DONNEES     20
int main (int argc, const char * argv[]) {
    // Variables pour la Plateforme de travail
    cl_platform_id plateformeID;
    cl_uint qtePlateformes;
    cl_int codeErreur;
    
    // Variables pour les périphériques contenant des unités de calcul
    cl_device_id TOUS_peripheriqueID; cl_uint TOUS_qtePeripheriques;
    // Variables pour les contextes de travail
    cl_context contexte; cl_context_properties proprietes[3];
    // Variable pour les files d'exécution des commandes
    cl_command_queue file_execution;
    // Variable pour la fonction à paralléliser
    cl_program programme;
    const char *maFonctionAuCarre = {
        "__kernel void auCarre(__global int *input, __global int *output)\n" "{\n"
        "    int id = get_global_id(0);\n"
        " output[id] = input[id] * input[id];" "}\n"
    };
    // Variable pour le noyau qui exécutera
    // le programme contenant la fonction parallèle.
    cl_kernel                   noyau;
    // Variables qui contiendront les données.
    int* inputData;
    int* outputData;
    cl_mem input_buffer;
    cl_mem output_buffer;
    // Initialisation des variables de données
    inputData = (int*)malloc(QTE_DONNEES * sizeof(int)); outputData = (int*)malloc(QTE_DONNEES * sizeof(int));
    for (int i = 0; i < QTE_DONNEES; i++) { inputData[i] = i;
        outputData[i] = 0;
    }
    // -------------------------------------------------------------------- // ----------------- Fin de la section des variables ------------------ // --------------------------------------------------------------------

    // Création de la plateforme de travail
    codeErreur = clGetPlatformIDs(1, &plateformeID, &qtePlateformes);
    // Rechercher les PÉRIPHÉRIQUES dans le système, tout type confondu.
    codeErreur = clGetDeviceIDs(plateformeID, CL_DEVICE_TYPE_ALL,
                                1,
                                &TOUS_peripheriqueID,
                                &TOUS_qtePeripheriques);
    // Création du contexte de travail
    proprietes[0] = (cl_context_properties) CL_CONTEXT_PLATFORM; proprietes[1] = (cl_context_properties) plateformeID; proprietes[2] = 0;
    contexte = clCreateContext(proprietes,
                               TOUS_qtePeripheriques,
                               &TOUS_peripheriqueID,
                               NULL,
                               NULL,
                               &codeErreur);
    // Création de la file d'exécution pour le CPU
    file_execution = clCreateCommandQueue(contexte, TOUS_peripheriqueID,
                                          0,
                                          &codeErreur);
    // Construire le programme avec la fonction auCarre pour le CPU
    programme = clCreateProgramWithSource(contexte, 1,
                                          (const char**)&maFonctionAuCarre, NULL,
                                          &codeErreur);
    // Compilation du programme
    codeErreur = clBuildProgram(programme, TOUS_qtePeripheriques,
                                &TOUS_peripheriqueID,
                                NULL,
                                NULL,
                                NULL);
    if (codeErreur != CL_SUCCESS) {
        // Si erreur de compilation, alors... Affichage du LOG de compilation
        char logErreurs[4096]; size_t longueur_Log;
        clGetProgramBuildInfo (programme, TOUS_peripheriqueID, CL_PROGRAM_BUILD_LOG,
                               sizeof(logErreurs), logErreurs, &longueur_Log);
        printf("\n[IMPRESSION DU JOURNAL DE COMPILATION]\n\n");
        printf("%s\n\n", logErreurs);
        printf("[FIN DU JOURNAL]\n\n");
