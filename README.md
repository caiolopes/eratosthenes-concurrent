# Sobre esses códigos

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa. Foram implementadas uma versão sequencial, uma versão paralelizada por controle e uma paralelizada por dados utilizando Pthreads.

## Grupo
- Caio de Sá Lopes
- Bruno Cepeda
- Guilherme Momesso

## Resultados

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa.

Na nossa análise, consideramos dois tamanhos para N: 5 milhões e 500 milhões.
Para as versões paralelizadas, utilizamos 2, 4 e 8 threads.

|            	| Threads 	| N             	| SpeedUp 	| Eficiência 	| Tempo 	|
|------------	|---------	|---------------	|---------	|------------	|-------	|
| Sequencial 	| -       	| 5.000.000      	|         	|            	|       	|
| Sequencial 	| -       	| 500.000.000 	  |         	|            	|       	|
| Dados      	| 2       	| 5.000.000      	|         	|            	|       	|
| Dados      	| 2       	| 500.000.000 	  |         	|            	|       	|
| Dados      	| 4       	| 5.000.000      	|         	|            	|       	|
| Dados      	| 4       	| 500.000.000 	  |         	|            	|       	|
| Dados      	| 8       	| 5.000.000      	|         	|            	|       	|
| Dados      	| 8       	| 500.000.000 	  |         	|            	|       	|
| Controle   	| 2       	| 5.000.000      	|         	|            	|       	|
| Controle   	| 2       	| 500.000.000 	  |         	|            	|       	|
| Controle   	| 4       	| 5.000.000      	|         	|            	|       	|
| Controle   	| 4       	| 500.000.000 	  |         	|            	|       	|
| Controle   	| 8       	| 5.000.000      	|         	|            	|       	|
| Controle   	| 8       	| 500.000.000 	  |         	|            	|       	|

Tabela 1: Diferentes desempenhos

## Análise dos resultados

