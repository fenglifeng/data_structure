silent! syn clear CTagsFunction CTagsEnumeratorName CTagsDefinedName CTagsEnumerationValue CTagsFile CTagsClass CTagsNamespace CTagsLocalVariable CTagsMember CTagsConstant CTagsGlobalVariable CTagsType CTagsUnion CTagsStructure CTagsFunction CTagsExtern
syntax keyword CTagsStructure QNode
syntax keyword CTagsMember data front next rear
syntax keyword CTagsFunction DeQueue EnQueue InitQueue QueueLength main
syntax keyword CTagsType LinkQueue QElemType QNode QueuePtr SqQueue
syntax keyword CTagsDefinedName MAXSIZE


if exists('b:hlrainbow') && !exists('g:nohlrainbow')
	syn cluster cBracketGroup add=CTagsStructure,CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCppBracketGroup add=CTagsStructure,CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCurlyGroup add=CTagsStructure,CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cParenGroup add=CTagsStructure,CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
	syn cluster cCppParenGroup add=CTagsStructure,CTagsMember,CTagsFunction,CTagsType,CTagsDefinedName,CTagsLocalVariable
endif
