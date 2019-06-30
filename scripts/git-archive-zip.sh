#!/bin/bash
#
#
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
# BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



echo "About to generate 'archive.zip' containing the contents of ${PWD}."
read -p "Are you sure you wish to perform this action [Yy/N]? " -n 1 -r
echo    # (optional) move to a new line
if ! [[ $REPLY =~ ^[Yy]$ ]]
then
	echo "Aborting"
	exit 1
fi

mytmpdir=`mktemp -d 2>/dev/null || mktemp -d -t 'mytmpdir'`

if [ ! -d "$mytmpdir" ]; then
	echo "Failed to create temporary directory"
	exit 1
fi

trap "{ echo Cleaning up...; rm -rf ${mytmpdir}; }" EXIT

if [ ! -x "./git-archive-all.sh" ]; then
	echo "git-archive-all.sh does not exist or is not executable"
	exit 1
fi


echo "Creating temporary tar archive..."
if ! ./git-archive-all.sh --format tar "${mytmpdir}/archive.tar"; then
	echo "Failed to create archive"
	exit 1
fi

GIT_REPO_DIR="${PWD}"

rm archive.zip

cd ${mytmpdir}
mkdir archive_extract
cd archive_extract
echo "Creating zip archive..."
tar xf ../archive.tar
zip -q -r ${GIT_REPO_DIR}/archive.zip .
cd ${GIT_REPO_DIR}
exit 0

