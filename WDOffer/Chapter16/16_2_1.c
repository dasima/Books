int search_binary(int a[], int first, int last, int x)
{
  int middle;
  while(first < last)
  {
    middle = (first + last) / 2;
    if(x == a[middle])
      return middle;
    else
    {
      if(a[first] < a[middle])//比较first跟middle的元素的大小，
      {//如果first到middle的元素大小有序
        if(x > a[middle])//如果x大于有序表的最大值，往后半部门查找
          first = middle + 1;
        else//如果x小于有序表的最大之
        {
          if(x > a[first])//且大于有序表的最小值，缩小范围
            last = middle - 1;
          else
            first = middle + 1;//否则，往后半部分查找,//这里可能是前半部分有序，最小元素可能在middle往后的列表中
        }
      }
      else//如果fisrt到middle的列表元素不是有序的
      {
        if(x < a[middle])//如果x比middle所在元素小，往前半部分查找
          last = middle - 1;
        else//如果x币middle所在元素大
        {
          if(x <= a[first])//并且比first所在元素小，往后半部分查找
            first = middle + 1;
          else//如果比first所在元素也大，往前半部分查找
            last = middle - 1;
        }
      }
    }//
  }//while  
}
