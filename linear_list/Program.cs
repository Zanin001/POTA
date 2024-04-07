
Console.WriteLine("-----Tipo de Lista-----");
Console.WriteLine("1 - Pilha");
Console.WriteLine("2 - Fila");
var listType = ListTypeHelper.GetListType(Console.ReadLine());

IList linearList = default;

if (listType == ListType.Unknowm)
{
    Console.WriteLine("Opção Invalida");
    return;
}

if (listType == ListType.Stack)
    linearList = new Stack();

if (listType == ListType.Queue)
    linearList = new Queue();

string option = "";
while (option != "0")
{
    Console.WriteLine("-----Menu-----");
    Console.WriteLine("__________________________");
    Console.WriteLine("1 - Inserir");
    Console.WriteLine("2 - Buscar");
    Console.WriteLine("3 - Exibir");
    Console.WriteLine("4 - Excluir");
    Console.WriteLine("0 - Sair ");
    Console.WriteLine("__________________________");   
    Console.WriteLine("Opção: ");
    option = Console.ReadLine();

    switch (option)
    {
        case "1":
        {   
            if (!TryGetInput("Novo valor a ser adicionado: ", out var newValue))
                break;

            var response = linearList.Insert(newValue);

            if (!response)
                Console.WriteLine("Elemento nao pode ser inserido na lista");
            else
                Console.WriteLine("Inserido com sucesso");

            break;
        }
        case "2":
        {
            if (!TryGetInput("Digite o valor procurado: ", out var valueToFind))
                break;

            var index = linearList.Search(valueToFind);

            if (index == -1)
                Console.WriteLine($"Valor {valueToFind} nao foi encontrado na lista");
            else
                Console.WriteLine($"O valor encontra-se na posicao {index}");  

            break;
        }
        case "3":
        {
            linearList.Show();
            break;
        }
        case "4":
        {
            if (!TryGetInput("Digite o valor a ser excluido: ", out var valueToRemove))
                break;

            var index = linearList.Search(valueToRemove);
            if (index == -1)
            {
                Console.WriteLine($"Valor {valueToRemove} nao foi encontrado na lista");
                break;
            }

            if (index != -1)
            {
                var response = linearList.Delete(index);

                if (!response)
                    Console.WriteLine("Elemento nao pode ser excluido da lista");
                else
                    Console.WriteLine("Excluido com sucesso");
            }

            break;
        }
    }

}

bool TryGetInput(string message, out int value)
{
    Console.WriteLine(message);
    var input = Console.ReadLine();
    if (!int.TryParse(input, out value))
    {
        Console.WriteLine("Valor não é um inteiro");
        return false;
    }

    return true;
}