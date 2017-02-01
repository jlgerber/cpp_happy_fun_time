#!/usr/bin/env python
import argparse


# since we are now passing in the greeting
# the logic has been consolidated to a single greet function
def greet(args):
    output = '{0}, {1}!'.format(args.greeting, args.name)
    if args.caps:
        output = output.upper()
    print(output)
#
# create a basic parser
#
def parsecmd():
    parser = argparse.ArgumentParser()

    parser.add_argument('name')
    # add greeting option w/ default
    parser.add_argument('--greeting', default='Hello')
    # add a flag (default=False)
    parser.add_argument('--caps', action='store_true')
    parser.set_defaults(func=greet)
    args = parser.parse_args()
    args.func(args)

if __name__ == '__main__':

    parsecmd()