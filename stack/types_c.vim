silent! syn clear CTagsFunction CTagsEnumeratorName CTagsDefinedName CTagsEnumerationValue CTagsFile CTagsClass CTagsNamespace CTagsLocalVariable CTagsMember CTagsConstant CTagsGlobalVariable CTagsType CTagsUnion CTagsStructure CTagsFunction CTagsExtern
syntax keyword CTagsMember data top
syntax keyword CTagsFunction Push
syntax keyword CTagsType SElemTYpe SqStack
syntax keyword CTagsDefinedName MAXSIZE


if exists('b:hlrainbow') && !exists('g:nohlrainbow')
	syn cluster cBracketGroup add=CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCppBracketGroup add=CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCurlyGroup add=CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cParenGroup add=CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCppParenGroup add=CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
endif
