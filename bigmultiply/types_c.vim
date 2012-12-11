silent! syn clear CTagsFunction CTagsEnumeratorName CTagsDefinedName CTagsEnumerationValue CTagsFile CTagsClass CTagsNamespace CTagsLocalVariable CTagsMember CTagsConstant CTagsGlobalVariable CTagsType CTagsUnion CTagsStructure CTagsFunction CTagsExtern
syntax keyword CTagsFunction bigmultiply main
syntax keyword CTagsLocalVariable a b i len1 len2 s


if exists('b:hlrainbow') && !exists('g:nohlrainbow')
	syn cluster cBracketGroup add=CTagsFunction,CTagsLocalVariable,CTagsLocalVariable
	syn cluster cCppBracketGroup add=CTagsFunction,CTagsLocalVariable,CTagsLocalVariable
	syn cluster cCurlyGroup add=CTagsFunction,CTagsLocalVariable,CTagsLocalVariable
	syn cluster cParenGroup add=CTagsFunction,CTagsLocalVariable,CTagsLocalVariable
	syn cluster cCppParenGroup add=CTagsFunction,CTagsLocalVariable,CTagsLocalVariable
endif
