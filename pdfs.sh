#!/usr/bin/env bash

echo "session 1"
pandoc -f markdown_github -t latex -o pdfs/session01.pdf session_01/session01.md
echo "session 2"
pandoc -f markdown_github -t latex -o pdfs/session02.pdf session_02/session02.md
echo "session 3"
pandoc -f markdown_github -t latex -o pdfs/session03.pdf session_03/session03.md
echo "session 4"
pandoc -f markdown_github -t latex -o pdfs/session04.pdf session_04/session04.md
echo "session 5"
pandoc -f markdown_github -t latex -o pdfs/session05.pdf session_05/session05.md
echo "session 6"
pandoc -f markdown_github -t latex -o pdfs/session06.pdf session_06/session06.md
echo "session 7"
pandoc -f markdown_github -t latex -o pdfs/session07.pdf session_07/session07.md
echo "session 8"
pandoc -f markdown_github -t latex -o pdfs/session08.pdf session_08/session08.md
echo "session 9"
pandoc -f markdown_github -t latex -o pdfs/session09.pdf session_09/session09.md
echo "session 10"
pandoc -f markdown_github -t latex -o pdfs/session10.pdf session_10/session10.md
echo "session 11"
pandoc -f markdown_github -t latex -o pdfs/session11.pdf session_11/session11.md
echo "session 12"
pandoc -f markdown_github -t latex -o pdfs/session12.pdf session_12/session12.md
echo "session rvalue ref"
pandoc -f markdown_github -t latex -o pdfs/rvalue_references_move_semantics.pdf rvalue_references_move_semantics/session.md