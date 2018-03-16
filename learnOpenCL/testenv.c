#include <stdlib.h>
#include <stdio.h>
#include <OpenCL/opencl.h>

int main (int argc, const char * argv[])
{
	// Variables pour la Plateforme de travail
	cl_platform_id plateformeID;
	cl_uint qtePlateformes;
	cl_int codeErreur;
	// Variables pour les périphériques contenant des unités de calcul
	cl_device_id	TOUS_peripheriqueID;
	cl_uint			TOUS_qtePeripheriques;
	cl_device_id	CPU_peripheriqueID;
	cl_uint			CPU_qtePeripheriques;
	cl_device_id	GPU_peripheriqueID;
	cl_uint			GPU_qtePeripheriques;

	// Création de la plateforme de travail
	codeErreur = clGetPlatformIDs(1, &plateformeID, &qtePlateformes);

	// Rechercher tous les PÉRIPHÉRIQUES dans le système.
	codeErreur = clGetDeviceIDs(plateformeID, CL_DEVICE_TYPE_ALL,
			1, &TOUS_peripheriqueID, &TOUS_qtePeripheriques);
	printf("Il y a au total %d peripherique(s) ", TOUS_qtePeripheriques); printf("de calcul dans cet ordinateur. Soit :\n");

	// Rechercher les CPU dans le système.
	codeErreur = clGetDeviceIDs(plateformeID, CL_DEVICE_TYPE_CPU,
			1, &CPU_peripheriqueID, &CPU_qtePeripheriques);
	printf(" - %d CPU(s)\n", CPU_qtePeripheriques);

	// Rechercher les GPU dans le système.
	codeErreur = clGetDeviceIDs(plateformeID, CL_DEVICE_TYPE_GPU, 1,
			&GPU_peripheriqueID, &GPU_qtePeripheriques);
	if (codeErreur == CL_DEVICE_NOT_FOUND)
		printf("  - Aucun GPU\n");
	else
		printf("- %d GPU(s)\n", GPU_qtePeripheriques);
	return (0);
}
