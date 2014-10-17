TEST_F(Directed, CreateBadCondition)
{
    InitQ(&q);
    q.head = (list_parameter_t*)1;
    RotateQ(&q);
}

