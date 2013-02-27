[BaseType(typeof(AGSSymbol))]
public interface AGSCompositeSymbol {

	[Export("symbols", ArgumentSemantic.Copy)]
	AGSSymbol[] Symbols { get; }

	[Static, Export("compositeSymbol")]
	AGSCompositeSymbol CompositeSymbol();

	[Export("addSymbol:")]
	void AddSymbol(AGSSymbol symbol);

	[Export("addSymbols:")]
	void AddSymbols(AGSSymbol[] symbols);

	[Export("removeSymbol:")]
	void RemoveSymbol(AGSSymbol symbol);

	[Export("removeAllSymbols")]
	void RemoveAllSymbols();

}