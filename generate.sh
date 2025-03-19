#!/bin/bash

ANTLR_PATH="third-party/antlr-tool/antlr.jar"

if [ -z $1 ]; then
	echo "Usage: ./generate.sh <grammar_name_in_grammars_dir))>"
	exit 1
fi

if [ -f "./grammars/$1.g4" ]; then
	:
else
	echo "Grammar $1 not found"
        exit 1
fi

GRAMMAR_NAME=$1


java -jar "${ANTLR_PATH}" -Dlanguage=Cpp -no-listener -visitor "grammars/${GRAMMAR_NAME}.g4"

if [ $? -ne 0 ]; then
        echo "ANTLR failed"
        exit 1
fi


mv "grammars/${GRAMMAR_NAME}Lexer.cpp" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}Parser.cpp" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}Visitor.cpp" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}BaseVisitor.cpp" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}.interp" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}.tokens" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}Lexer.tokens" "./src/antlr-generated/"
mv "grammars/${GRAMMAR_NAME}Lexer.interp" "./src/antlr-generated/"
cd grammars
mv *.h "../headers/antlr-generated/"
cd ..
exit 0
