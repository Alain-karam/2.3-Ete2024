# Variables pour les programmes et fichiers sources
PROGS = 1-StructuresEtUnions 2-Static
SOURCES = 1-StructuresEtUnions.c 2-Static.c
OBJS = 1-StructuresEtUnions.o 2-Static.o

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

# Règle par défaut : compiler tous les exécutables
all: $(PROGS)

# Règles explicites pour chaque exécutable
1-StructuresEtUnions: 1-StructuresEtUnions.o
	$(CC) -o $@ $< $(LDFLAGS)

2-Static: 2-Static.o
	$(CC) -o $@ $< $(LDFLAGS)

# Règles génériques pour les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean exec

# Nettoyage des fichiers objets et des exécutables
clean:
	rm -f $(OBJS) $(PROGS)

# Exécuter les programmes avec différents arguments
exec: $(PROGS)
	@echo "------------------------"
	./1-StructuresEtUnions || true
	@echo "------------------------"
	./1-StructuresEtUnions 1 1 1
	@echo "------------------------"
	./1-StructuresEtUnions 1 2 1
	@echo "------------------------"
	./1-StructuresEtUnions -1 -1 1
	@echo "------------------------"
	./2-Static
	@echo "------------------------"
