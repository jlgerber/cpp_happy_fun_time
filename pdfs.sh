#!/usr/bin/env bash

pandoc -f markdown_github -t latex -o pdfs/session01.pdf session_01/session01.md
pandoc -f markdown_github -t latex -o pdfs/session02.pdf session_02/session02.md
pandoc -f markdown_github -t latex -o pdfs/session03.pdf session_03/session03.md
pandoc -f markdown_github -t latex -o pdfs/session04.pdf session_04/session04.md
pandoc -f markdown_github -t latex -o pdfs/session05.pdf session_05/session05.md