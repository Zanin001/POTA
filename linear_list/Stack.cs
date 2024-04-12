

public class Stack : IList
{
    private int?[] LinearList;

    public Stack()
    {
        LinearList = new int?[3];
    }
    

    public bool Delete()
    {
        try
        {
            for (int i = LinearList.Length - 1; i >= 0; i--)
            {
                if (LinearList[i] != null)
                {
                    LinearList[i] = null;
                    break;
                }
            }

            return true;
        }
        catch (Exception e)
        {
            return false;
        }
    }

    public bool Insert(int value)
    {        
        var top = GetTop();

        if (top >= LinearList.Length - 1)
            return false;
        
        LinearList[top + 1] = value;
        
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
            Console.WriteLine("Pilha vazia");
            return;
        }

        Console.WriteLine("Valores na pilha:");
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