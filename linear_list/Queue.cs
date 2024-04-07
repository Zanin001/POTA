

public class Queue : IList
{
    private int?[] LinearList;
    
    public Queue()
    {
        LinearList = new int?[3];
    }
    public bool Delete(int index)
    {
        var top = GetTop();
        if (index < 0 || index > top)
            return false;

        for (int i = index; i < top; i++)
            LinearList[i] = LinearList[i + 1];

        LinearList[GetTop()] = null;

        return true;
    }

    public bool Insert(int value)
    {
        var top = GetTop();

        if (top >= LinearList.Length - 1)
            return false;
        
        for (int i = top + 1; i > 0; i--)
            LinearList[i] = LinearList[i - 1];

        LinearList[0] = value;

        return true;
    }

    public int Search(int value)
    {
        var top = GetTop();
        for (int i = 0; i <= top; i++)
        {
            if (LinearList[i] == value)
                return i;
        }
        return -1;
    }

    public void Show()
    {
        int top = GetTop();

        if (top == -1)
        {
            Console.WriteLine("Fila vazia");
            return;
        }

        Console.WriteLine("Valores na fila:");
        for (int i = 0; i <= top; i++)
        {
            Console.WriteLine(LinearList[i]);
        }
    }

    private int GetTop()
    {
        for (int i = LinearList.Length - 1; i >= 0; i--)
        {
            if (LinearList[i] != null)
                return i;
        }

        return -1;
    }
}