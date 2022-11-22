#include<stdio.h>

void main()
{
	FILE *fi = fopen("./input.txt", "r");
	FILE *fo = fopen("./output.txt", "w");

	if (fi == NULL){
		printf("File khong ton tai!");
		return;
	}

    int pn[10];
    int bur[10], star[10], finish[10], tat[10], wt[10], bur_tam[10], i, n, qt;
    int tam[10], arr[10];
    int time = 0, tong_bur = 0, flag1[10], flag2[10];
    int totwt = 0, tottat = 0;

    fscanf(fi, "%d%d", &n, &qt);

    for (i = 0; i < n; i++){
        fscanf(fi, "%d%d", &pn[i], &bur[i]);
        bur_tam[i] = bur[i];
        tong_bur += bur[i];
        flag1[i] = flag2[i] = arr[i] = wt[i] = tam[i] = 0; 
    }
    i =0;

    while (time != tong_bur){
        if (bur_tam[i] <= qt && bur_tam[i] > 0){ //lan chay cuoi cung
            if(flag2[i] == 0)
	    	star[i] = time;
            fprintf(fo, "%d %d ", pn[i], time);
            wt[i] += time - tam[i];
            time += bur_tam[i];
            bur_tam[i] = 0;
            flag1[i] = 1;
            finish[i] = time;
            fprintf(fo, "%d\n", time);
        }else if(bur_tam[i] > 0){ 
            fprintf(fo, "%d %d ", pn[i], time);
            if (flag2[i] == 0){
                star[i] = time;
                flag2[i] = 1;
            }else{
                wt[i] += time - tam[i];
            }
            bur_tam[i] -= qt;
            time += qt;
            tam[i] = time;
            fprintf(fo, "%d\n", time);
        }
        
        if (flag1[i] == 1 && bur_tam[i] == 0){
            totwt += wt[i];
            tottat += finish[i] - arr[i];
            flag1[i] = 0;
        }

        if (i == n - 1)
            i = 0;
        else
            i++;
    }
    for (i = 0; i < n; i++){//mac dinh arr[i] = 0 nen thoi gian cho phai cong them thoi gian dap ung
        totwt += star[i];
    }
    fprintf(fo, "%.2f\n%.2f", totwt * 1.0/n, tottat * 1.0/n);
    fclose(fi);
    fclose(fo);
}
