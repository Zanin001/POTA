public enum ListType
{
    Unknowm,
    Stack,
    Queue
}

public static class ListTypeHelper
{
    public static ListType GetListType(string type)
    {
        if (int.TryParse(type, out var value))
            if (Enum.IsDefined(typeof(ListType), value))
                return (ListType)value;

        return ListType.Unknowm;
    }
}