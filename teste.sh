#!/bin/bash

PROJECT_PATH=$HOME/git/Emulador-De-Arquitetura-De-Computador
make -C "$PROJECT_PATH/build"
"$PROJECT_PATH/build/project" "$PROJECT_PATH/testes/test_machine.json"
exit 0


