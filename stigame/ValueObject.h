#ifndef VALUEOBJECT_H
#define VALUEOBJECT_H

namespace StiGame {

/// \class ValueObject
/// \brief Class for GuiItem list
class ValueObject
{
    public:
        /// \brief Constructor
        ValueObject();
        /// \brief Constructor
        /// New value object with specified param
        /// \param m_id Value Id
        /// \param m_text Value Text
        ValueObject(int m_id, char* m_text);
        /// \brief Destructor
        virtual ~ValueObject();
        /// \brief Get the value text
        /// \return value text
        char *getText(void);
        /// \brief Get he value id
        /// \return value id
        int getId(void);
    protected:
        /// \brief Value Id
        int id;
        /// \brief Value Text
        char *text;
    private:
};

}

#endif // VALUEOBJECT_H
